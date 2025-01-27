class Solution:
    def repeatedStringMatch(self, a: str, b: str) -> int:
        p, m = 31, 10 ** 9 + 9
        A, B = len(a), len(b)
        min_repeat_a = math.ceil(B / A)
        max_repeat_a_len = A * (min_repeat_a + 1) 
        p_pow = [1 for _ in range(max_repeat_a_len)]
        for i in range(1, len(p_pow)):
            p_pow[i] = (p_pow[i - 1] * p) % m
        
        ha = [0 for _ in range(max_repeat_a_len + 1)]
        for i in range(max_repeat_a_len):
            ha[i + 1] = (ha[i] + (ord(a[i % A]) - ord("a") + 1) * p_pow[i]) % m
        
        hb = 0
        for i in range(B):
            hb = (hb + (ord(b[i]) - ord("a") + 1) * p_pow[i]) % m
        
        for i in range(max_repeat_a_len - B + 1):
            cur_h = (ha[i + B] - ha[i] + m) % m
            if cur_h == hb * p_pow[i] % m: return math.ceil((i + B) / A)

        return -1