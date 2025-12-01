import sys

def main(lines):
    s = lines[0]
    print("Hello {{{}}}!".format(s))

if __name__ == '__main__':
    lines = []
    for l in sys.stdin:
        lines.append(l.rstrip('\r\n'))
    main(lines)