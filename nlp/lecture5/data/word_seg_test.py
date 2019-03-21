# encoding=utf-8
import re
import jieba
from jieba import posseg

# 加载字典
def load_word_list():
    max_length = 0
    word_dict = set()
    for line in open('./data/corpus.dict.txt', encoding='utf-8', errors='ignore').readlines():
        tmp = len(line)
        if(max_length < tmp):
            max_length = tmp
        word_dict.add(line.strip())
    return {
        'max_length': max_length,
        'word_dict': word_dict
    }

dictionary = load_word_list()

# 最大正向匹配
def max_left_match(line):
    max_len = dictionary['max_length']
    words = dictionary['word_dict']
    result = []
    i = 0
    while i < len(line):
        subpart = line[i:i+max_len] if max_len + i <= len(line) else line[i:]
        while subpart not in words and len(subpart) != 1:
            subpart = subpart[:len(subpart)-1]
        result.append(subpart)
        i += len(subpart)
    return result

# 最大逆向匹配
def max_right_match(line):
    max_len = dictionary['max_length']
    words = dictionary['word_dict']
    result = []
    i = len(line)
    while i > 0:
        subpart = line[i-max_len:i] if i-max_len >= 0 else line[:i]
        while subpart not in words and len(subpart) != 1:
            subpart = subpart[1:]
        result.append(subpart)
        i -= len(subpart)
    result.reverse()
    return result

def bi_dirctional_mm(line):
    forward_result = max_left_match(line)
    backward_result = max_right_match(line)
    return forward_result if len(forward_result) < len(backward_result) else backward_result

def jieba_cut(line):
    return jieba.cut(line)

def jieba_pos_tokenize(line):
    words = posseg.cut(line)
    return ['%s %s ' % (word, flag) for word, flag in words]

def remove_symbol(line):
    punctuation = '！？｡。＂＃＄％＆＇（）＊＋，－／：；＜＝＞＠［＼］＾＿｀｛｜｝～｟｠｢｣､、〃《》「」『』【】〔〕〖〗〘〙〚〛〜〝〞–—‘’‛“”„‟…‧﹏.'
    pattern = '[%s]+' % punctuation
    pat = re.compile(pattern)
    sentences = pat.split(line)
    return sentences

# 测试
def test(output, matcher):
    allResult = []
    for line in open('./data/corpus.sentence.txt', encoding='utf-8', errors='ignore').readlines():
        # 去标点
        sentences = remove_symbol(line)
        # 最大匹配
        for sentence in sentences:
            sentence = sentence.strip()
            if not sentence:
                continue
            # 结果
            result = matcher(sentence)
            for word in result:
                output.write('%s ' % word)
                allResult.append(word)

        output.write('\n')
    return allResult


def getPrecisionRecall(predict, target):
    detectedSamples = len(predict)
    actualSamples = len(target)
    def toIndexes(words):
        index = 0
        res = []
        for word in words:
            res.append((index, index + len(word)))
            index += len(word)
        return res
    pIndexes = toIndexes(predict)
    tIndexes = toIndexes(target)
    corrects = sum([1 if index in tIndexes else 0 for index in pIndexes])
    precision = corrects / detectedSamples
    recall = corrects / actualSamples
    return precision, recall, (2 * precision * recall) / (precision + recall)

def main():
    results = {}
    prf = {}
    results['standard'] = []
    for line in open('./data/corpus.standard.txt').readlines():
        results['standard'].extend([word.strip() for word in line.split(' ')])

    with open('./corpus.out.txt', mode='w') as output:
        results['left'] = test(output, max_left_match)
        prf['left'] = getPrecisionRecall(results['left'], results['standard'])

    with open('./bmm.out.txt', mode='w') as output:
        results['right'] = test(output, max_right_match)
        prf['right'] = getPrecisionRecall(results['right'], results['standard'])

    with open('./bi.out.txt', mode='w') as output:
        results['bi'] = test(output, bi_dirctional_mm)
        prf['bi'] = getPrecisionRecall(results['bi'], results['standard'])

    jieba.load_userdict('./data/corpus.dict.txt')
    with open('./jieba.out.txt', mode='w') as output:
        results['jieba'] = test(output, jieba_cut)
        prf['jieba'] = getPrecisionRecall(results['jieba'], results['standard'])

    print("Size: ")
    print('Left: %d' % len(results['left']))
    print('Right: %d' % len(results['right']))
    print('Bi: %d' % len(results['bi']))
    print('jieba: %d' % len(results['jieba']))
    print('standard: %d' % len(results['standard']))


    print("\nP/R/F: ")
    print('Left: %f / %f / %f' % prf['left'])
    print('Right: %f / %f / %f' % prf['right'])
    print('Bi: %f / %f / %f' % prf['bi'])
    print('jieba: %f / %f / %f' % prf['jieba'])

    #词性
    with open('./POS.txt', mode='w') as output:
        test(output, jieba_pos_tokenize)


if __name__ == '__main__':
    main()
