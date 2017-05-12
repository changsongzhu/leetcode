/**
190[E]. Reverse Bits
Reverse bits of a given 32 bits unsigned integer.
For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).
Follow up:
If this function is called many times, how would you optimize it?
**/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res=0;
        for(int i=0;i<32;i++)
        {
            if((n&1)==1)
                res=(res<<1)+1;
            else
                res=res<<1;
            n=n>>1;
        }
        return res;
    }
};



//for follow up, using the look up table to optimize it
char lookup_table[16] = {0, 8, 4, 9, 2, 10,6, 14, 1, 9, 5, 13, 3, 11, 7, 15};

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res=0;
        for(int i=0;i<8;i++)
        {
            char tmp=n&0xF;
            res=(res<<4)+lookup_table[tmp];
            n=n>>4;
        }
        return res;
    }
};
