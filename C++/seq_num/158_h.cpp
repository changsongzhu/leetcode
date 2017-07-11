/**
158[H]. Read N Characters Given Read4 II – Call Multiple Times
The API: int read4(char *buf) reads 4 characters at a time from a file.
The return value is the actual number of characters read. For example, it returns 3 if there is only 3 characters left in the file.
By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file.
Note:
The read function may be called multiple times.
**/

class Solution {
public:
    int read(char *buf, int n) {
        for(int i=0;i<n;i++)
        {
            if(readOffset==writeOffset)
            {
                readOffset=read4(tmp);
                writeOffset=0;
                if(readOffset==0) return i
            }
            buf[i]=tmp[writeOffset++];
        }
        return n;
   }
private:
    int readOffset=0, writeOffset=0;
    char tmp[4];
};

