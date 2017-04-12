from subprocess import check_output
import os

def invalid(value):
    checked = [False] * 10
    while value > 0:
        digit = value % 10
        if checked[digit]:
            return True
        checked[digit] = True
        value = value / 10
    return False


for i in range(1234, 9876):
    if invalid(i):
        continue
    for j in range(1234, 9876):
        if invalid(j):
            continue
        output = check_output('echo -e "%d\n%d" | nc bullandcow-challenge.framgia.vn 2015 | tail -n +11' % (i, j), shell=True)
        if 'Correct' not in output:
            break
        print i, j
