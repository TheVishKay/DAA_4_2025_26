# HUFFMAN ENCODING AND DECODING
# Write a program to read an input string, encode it using Huffman coding, and then decode the encoded bit sequence to obtain the original input string.

# Your program should:

# Calculate the frequency of each character.

# Construct the Huffman tree.

# Generate Huffman codes for each character.

# Encode the input string using these codes.

# Decode the encoded string using the Huffman tree.

# Display the original string, encoded string, and decoded string.
import heapq
from collections import Counter

class Node:
    def __init__(self, ch, freq):
        self.ch = ch
        self.freq = freq
        self.left = None
        self.right = None
    def __lt__(self, other):
        return self.freq < other.freq

def generate_codes(root, code, huffman):
    if not root:
        return
    if not root.left and not root.right:
        huffman[root.ch] = code
    generate_codes(root.left, code + "0", huffman)
    generate_codes(root.right, code + "1", huffman)

def decode(root, encoded):
    res = ""
    curr = root
    for b in encoded:
        curr = curr.left if b == "0" else curr.right
        if not curr.left and not curr.right:
            res += curr.ch
            curr = root

s = input("enter string ")

freq = Counter(s)
heap = [Node(ch, f) for ch, f in freq.items()]
heapq.heapify(heap)

while len(heap) > 1:
    a = heapq.heappop(heap)
    b = heapq.heappop(heap)
    p = Node("", a.freq + b.freq)
    p.left = a
    p.right = b
    heapq.heappush(heap, p)

root = heap[0]
huffman = {}
generate_codes(root, "", huffman)

encoded = "".join(huffman[c] for c in s)


print("Original String:", s)
print("Encoded :", encoded)


