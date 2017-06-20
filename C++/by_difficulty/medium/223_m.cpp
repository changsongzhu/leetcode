/**
223[M]. Rectangle Area
Find the total area covered by two rectilinear rectangles in a 2D plane.
Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.
Assume that the total area is never beyond the maximum possible value of int.
**/

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int x=0,y=0;
        if(A>G||C<E)
        {
            x=0;
        }
        else if((E<C&&E>=A)||(A<G&&A>=E))
        {
            x=min(G, C)- max(A, E);
        }
        if(F>D||H<B)
        {
           y=0;
        }
        else if((B>=F&&B<H)||(F>=B&&F<D))
        {
           y=min(D, H)-max(B, F);
        }
        return (C-A)*(D-B)+(G-E)*(H-F)-x*y;
    }
};

