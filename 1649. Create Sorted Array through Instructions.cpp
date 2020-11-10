class Solution {
typedef int item;
struct segtree{ // zero indexing
        int size;
        vector<item> arr;

        const item NU= 0; //value don't change the function 0 for sum INT_MAX or min ...

        item single(int val) { // what is in the leaf of the tree
                return val;
        }

        item merge_(item a, item b) {
                return a+ b;
        }

        void init(int n) {
                size= 1;
                while (size< n) size*= 2;
                arr.resize(2* size);
        }

        void build(vector<int> &v, int x, int l, int r) {
                if (r- l== 1) {
                        if (l< (int)v.size())
                                arr[x]= single(v[l]);
                        return;
                }
                int md= (l+ r)/ 2;
                build(v, x* 2+ 1, l, md);
                build(v, x* 2+ 2, md, r);
                arr[x]= merge_(arr[x* 2+ 1], arr[x* 2+ 2]);
        }

        void build(vector<int> &v) {
                build(v, 0, 0, size);
        }

        void set(int idx, int val, int x, int l, int r) {
                if (r- l== 1) {
                        arr[x]+= single(val);
                        return;
                }
                int md= (l+ r)/ 2;
                if (idx>= md) {
                        set(idx, val, x* 2+ 2, md, r);
                } else
                        set(idx, val, x* 2+ 1, l, md);
                arr[x]= merge_(arr[x* 2+ 1], arr[x* 2+ 2]);
        }

        void set(int idx, int val) {
                set(idx, val, 0, 0, size);
        }

        item calc(int gl, int gr, int x, int l, int r) {
                if (l>= gr|| r<= gl) return NU;
                if (l>= gl&& r<= gr) return arr[x];
                int md= (l+ r)/ 2;
                item an1= calc(gl, gr, x* 2+ 2, md, r);
                item an2= calc(gl, gr, x* 2+ 1, l, md);
                return merge_(an1, an2);
        }

        item calc(int l, int r) { // from l to r- 1
                return calc(l, r, 0, 0, size);
        }

};
public:
    int createSortedArray(vector<int>& ar) {
        int N= 1e5+ 1;
        segtree sg;
        sg.init(N);
        vector<int> v(N, 0);
        sg.build(v);
        auto add=[&] (int &a, int b) {
            const int MOD= 1e9+ 7;
            a+= b;
            if (a>= MOD) a-= MOD;
        };
        int sm= 0;
        for (int i= 0; i< ar.size(); i++) {
            int l= sg.calc(0, ar[i]);
            int r= sg.calc(ar[i]+ 1, N);
            add(sm, min(l, r));
            sg.set(ar[i], 1);
        }
        return sm;
    }
};
