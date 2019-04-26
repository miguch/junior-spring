# encoding=utf-8
import re
import jieba
from jieba import posseg

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

def test(matcher, name):
    allResult = []
    for line in open(name, encoding='utf-8', errors='ignore').readlines():
        # 去标点
        sentences = remove_symbol(line)
        # 匹配
        for sentence in sentences:
            sentence = sentence.strip()
            if not sentence:
                continue
            # 结果
            result = matcher(sentence)
            allResult.extend(result)

    return allResult


def main():
    allWords = set()
    with open('./splits/words.txt', mode='w') as output:
        for i in range(1, 194):
            filename = 'page/%d.txt' % i
            allWords.update(test(jieba_cut, filename))
        for w in allWords:
            output.write('%s ' % w)


if __name__ == '__main__':
    main()
