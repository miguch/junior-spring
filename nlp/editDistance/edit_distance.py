import difflib
def edit_distance(str1, str2):
    len_str1 = len(str1) + 1
    len_str2 = len(str2) + 1
    matrix = [0 for n in range(len_str1 * len_str2)]
    for i in range(len_str1):
        matrix[i] = i
    for j in range(0, len(matrix), len_str1):
        matrix[j] = j
    for i in range(1, len_str1):
        for j in range(1, len_str2):
            if str1[i-1] == str2[j-1]:
                cost = 0
            else:
                cost = 1
            matrix[j*len_str1 + i] = min(matrix[(j-1)*len_str1+i] + 1,
                                        matrix[j*len_str1+i-1] + 1,
                                        matrix[(j-1)*len_str1+i-1] + cost)
    return matrix[-1]

def dp_edit_distance(str1, str2):
    if not str2:
        return len(str1)
    len_str1 = len(str1) + 1
    len_str2 = len(str2) + 1
    dp = [i for i in range(len_str2)]
    for i in range(1, len_str1):
        dp[0] = i - 1
        curr = i - 1
        for j in range(1, len_str2):
            hold = dp[j]
            if str1[i-1] == str2[j-1]:
                dp[j] = min(dp[j] + 1, dp[j-1] + 1, curr)
            else:
                dp[j] = min(dp[j] + 1, dp[j-1] + 1, curr + 1)
            curr = hold
    return dp[-1]

def difflib_edit_distance(str1, str2):
    leven_cost = 0;
    s = difflib.SequenceMatcher(None, str1, str2)
    for tag, i1, i2, j1, j2 in s.get_opcodes():
        if tag == 'replace':
            leven_cost += max(i2-i1, j2-j1)
        elif tag == 'insert':
            leven_cost += (j2 - j1)
        elif tag == 'delete':
            leven_cost += (i2 - i1)
    return leven_cost

str1 = input("str1: ")
str2 = input("str2: ")
print("edit_distance: %i" % edit_distance(str1, str2))
print("difflib_edit_distance: %i" % difflib_edit_distance(str1, str2))
print("dp_edit_distance: %i" % dp_edit_distance(str1, str2))
