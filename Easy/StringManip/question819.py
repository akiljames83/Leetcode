class Solution:
    def mostCommonWord(self, p: 'str', banned: 'List[str]') -> 'str':
        p = p.replace(",", " ").replace(".", " ").replace("!"," ").replace("?"," ").replace("'"," ").replace(";"," ").lower()
        arr = p.split()
        dic = dict()
        ban = set(banned)
        for a in arr:
            if a in dic:
                dic[a] += 1
            else:
                dic[a] = 1
        while True:
            key = max(dic.items(), key=operator.itemgetter(1))[0]
            if key in ban:
                del dic[key]
            else:
                return key