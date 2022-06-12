t = int(input())
operands = ['+', '-', '*', '//']
values = {}
for i in operands :
    for j in operands :
        for k in operands :
            s = "4 {:s} 4 {:s} 4 {:s} 4".format(i, j, k)
            val = eval(s)
            values[val] = s.replace('//', '/') + " = {:d}".format(val)
for i in range(0, t) :
    n = int(input())
    if n not in values :
        print("no solution")
    else :
        print(values[n])
