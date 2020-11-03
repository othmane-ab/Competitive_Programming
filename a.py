a = {}
b = {}
# n = input()
# t = input()
# t = t.split(" ")
# t = [int(i) for i in t]
# t = t.sort()
t = [2,8,3]

b_a, b_b = 0, 0
t_a, t_b = t[0], t[1]
a_read = [0 for e in t]
b_read = [0 for e in t]

a_done = 0
b_done = 0



for t_ in range(sum(t)*2):
    print(t_)
    if t_a>1:
        t_a -= 1
    else:
        t_a = 0
        a_read[b_a] = 1
        if b_a == len(a_read)-1:
            a_done = 1
            print("a done")
        else:
            if (b_a + 1 <= len(a_read)-1):
                if (b_b != b_a+1):
                    b_a = b_a + 1
                    t_a = t[b_a]
                else:
                    if b_a + 2 <= len(a_read)-1:
                        b_a = b_a + 2
                        t_a = t[b_a]    
    if t_b>1:
        t_b -= 1
    else:
        t_b = 0
        b_read[b_b] = 1
        if b_b == len(b_read)-1:
            b_done = 1
            print("b done")
        else:
            if (b_b + 1 <= len(b_read)-1):
                if (b_b != b_a+1):
                    b_b = b_b + 1
                    t_b = t[b_b]
                else:
                    if b_b + 2 <= len(b_read)-1:
                        b_b = b_b + 2
                        t_b = t[b_b]
