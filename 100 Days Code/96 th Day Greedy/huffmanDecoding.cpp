/*
Input :
binaryString = 
0000000000001100101010101011111111010101010
Min Heap Tree =  
                $(20)
              /      \
            /          \
         $(8)            \
       /     \             \
    $(3)      \            $(12)
    /  \       \           /    \
B(1)    D(2)    E(5)    C(6)    A(6)

Output: AAAAAABCCCCCCDDEEEEE

Explanation:
The following chart can be made from the 
given min heap tree.
character    frequency    code
    A             6        00                 
    B             1        110
    C             6        01
    D             2        111    
    E             5        10

*/

string decodeHuffmanData(struct MinHeapNode* root, string binaryString)
{
    // Code here
    string s="";
    MinHeapNode *t = root;
    int i=0;
    while(i<binaryString.size()+1){
        if(t->data=='$'){
            if(binaryString[i]=='0')
                t=t->left;
            else
                t=t->right;
        i++;
        }
        else{
            s+=t->data;
            t=root;
        }
    }
    return s;
}
