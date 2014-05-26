__author__ = 'frsilent'

def more(text, numlines = 15):
    """
    breaks up a text file into sections so users can scroll through it with y/Y
    """
    lines = text.split('\n')
    while lines:
        chunk = lines[:numlines]
        lines = lines[numlines:]
        for line in chunk: print(line)
        if lines and input('More?') not in ['y', 'Y']: break

if __name__ == '__main__':
    import sys
    more(open(sys.argv[1]).read(), 10)