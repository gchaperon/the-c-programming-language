#!/usr/bin/env python3
import random, argparse, string, math

parser = argparse.ArgumentParser()
parser.add_argument("--line-length", default=20, type=int)
parser.add_argument("--nlines", default=100, type=int)
parser.add_argument("--shuffle", action="store_true")
parser.add_argument("--show-lineno", action="store_true")
parser.add_argument("--use-punctuation", action="store_true")


args = parser.parse_args()
pad = len(str(args.nlines))
punctuation = string.punctuation if args.use_punctuation else []
lines = [
    (f"{i: <{pad}} " if args.show_lineno else "")
    + "".join(
        random.choices(
            string.ascii_letters + punctuation,
            weights=[5]*len(string.ascii_letters) + [2] * len(punctuation),
            k=args.line_length,
        )
    )
    for i in range(args.nlines)
]
if args.shuffle:
    random.shuffle(lines)

for line in lines:
    print(line)
