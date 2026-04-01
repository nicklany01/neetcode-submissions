class Solution:
    def isValid(self, s: str) -> bool:
        st = deque()
        for x in s:
            if x in "({[":
                st.append(x)
                print(x)
            if x in "}])":
                if st:
                    popped = st.pop()
                else:
                    return False
                if popped == '[' and x != ']' or popped == '(' and x != ')' or popped == '{' and x != '}':
                    return False
        if not st:
            return True
        else:
            return False