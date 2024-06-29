# Huffman File Compression

This project is based on Huffman Coding, a lossless, bottom-up compression algorithm. It can compress and decompress any text files.

To learn more about Huffman Coding and its applications in Information Theory read this article.

Implementation in Project
This project supports two functions:
1. Encode: Compresses input file passed.
2. Decode: Decompresses Huffman coded file passed back to its original file.

`struct Node` represents a node of Huffman Tree which is generated during compression or decompression of files. It stores character data, its frequency, Huffman code, and two pointers that point towards the left or right node if they exist.

Huffman class contains only two public functions
1. compress()
2. decompress()
And a constructor which accepts input file and output file. The object of this class can be initiated as follows: 
`huffman obj(inputFileName, outputFileName)`;


Compressing file `compress()`: Following are the steps followed to compress the input file.

1. `createMinHeap()`: This function reads the input file and stores the frequency of all the characters appearing in the file. It further creates a Min Heap structure based on the frequency of each character using priority queue as a data structure that stores Nodes and uses its frequency as a comparing parameter.

2. `createTree()`: This function generates the Huffman tree by duplicating the Min Heap created earlier keeping the original Min Heap. It pops the two Nodes with the lowest frequency. Further, it assigns these two as left and right nodes to a new Node with a frequency which is the sum of the two popped nodes and pushes this Node back to the Min Heap. This process is continued until Min Heap has a size equal to 1.

3. `createCodes()`: This function traverses the entire Huffman tree and assigns codes in binary format to every Node.

4. `saveEncodedFile()`: This function saves the Huffman encoded input file to the output file. The image below illustrates how the output file is written.


`minHeap = ({character data} {huffman code for that character}) * minheapsize`


Decompressing file `decompress()`: Following are the steps followed to decompress the Huffman encoded file.

1. `getTree()`: This function reads the Min Heap stored at the beginning of the file and reconstructs the Huffman tree by appending one Node at a time. MinHeapSize is the first value, next {MinHeapSize * (1+16)} contains character data and 16 decimal values representing 128 bits of binary Huffman code. Ignore the initial (127 - code.length()) of '0's and starting '1' bit and append the Node.

2. `saveDecodedFile()`: This function reads the entire {Encoded input File charachters} and {count0} by ignoring the first {MinHeapSize * (1 + 16)} of the file. The decimal values are converted to their binary equivalent(huffman codes) and the resulting character is appended to the output file by traversing the reconstructed huffman tree. The final count0 number of '0's are ignored since they were extra bits added while saving the encoded file.

## How to run this project?
To run this project you need to create an executable file. You can follow the steps given below:
1. For compressing:
```sh
PS C:\Users\Ankit Pandey\Desktop\Me\Projects\Huffman-File-Compression> g++ huffman.cpp -o main
PS C:\Users\Ankit Pandey\Desktop\Me\Projects\Huffman-File-Compression> .\main.exe
Enter your choice (1 for compress, 2 for decompress): 1
Enter the name of the input file: inputFile.txt
Enter the name for the compressed file: compressedFile.txt
Compressed successfully
```

2. For Decompressing:
```sh
PS C:\Users\Ankit Pandey\Desktop\Me\Projects\Huffman-File-Compression> g++ huffman.cpp -o main
PS C:\Users\Ankit Pandey\Desktop\Me\Projects\Huffman-File-Compression> .\main.exe
Enter your choice (1 for compress, 2 for decompress): 2
Enter the name of the compressed file: compressedFile.txt
Enter the name for the output file: outputFile.txt
Decompressed successfully
```

## Result
This project is just an implementation of Huffman coding, it is not as efficient as the compression algorithm used currently to compress files.
Example: inputFile.txt (4KB) is compressed to compressedFile.txt (1.9 KB) file and decompressed back to ouputFile.txt (4KB).