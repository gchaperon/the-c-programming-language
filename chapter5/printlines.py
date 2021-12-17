import random, string, argparse

parser = argparse.ArgumentParser()
parser.add_argument("--nlines", default=100, type=int)
parser.add_argument("--line-length", default=10, type=int)

args = parser.parse_args()

for i in range(args.nlines):
    print(f"{i: 5} " + "".join(random.choices(string.ascii_letters, k=args.line_length)))
