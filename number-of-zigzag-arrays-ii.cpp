// class Solution {
//     const int mod = 1e9 + 7;
// public:
//     long[][] power(long a [][], int m, int b){
//         long res[m][m];

//         for(int i=0; i<m; i++){
//             res[i][i] = 1;
//         }

//         while(b>0){
//             if(b&1){
//                 res = mul(res,a);
//             }
//             a = mul(a,a);
//             b >>= 1;
//         }

//         return res;
//     }

//     long [][] mul(long a [][], size, long b [][], size){
//         long res [size][size];

//         for(int i=0; i<size; i++){
//             for(int j=0; j<size; j++){
//                 long sum = 0;
//                 for(int k=0; k<size; k++){
//                     sum = (sum + (a[i][k] * b[k][j])%mod)%mod;
//                 }
//                     res[i][j] = sum;
//             }
//         }

//         return res;
//     }

//     long [] multiply(long a [][], size, long b [], size){
//         long res [size];

//         for(int i=0; i<size; i++){
//             for(int j=0; j<size; j++){
//                 long sum = 0;
//                 for(int k=0; k<size; k++){
//                     sum = (sum + (a[i][k] * b[k][j])%mod)%mod;
//                 }
//                 res[i] = sum;
//             }
//         }

//         return res;
//     }


//     int zigZagArrays(int n, int l, int r) {
//         int m = r - l + 1;
//         int size = 2*m;

//         long base[size];

//         for(int i=0; i<m; i++){
//             base[i] = i; // up
//             base[i+m] = m - 1 - i; //down
//         }

//         long transition[size][size];

//         for(int v = 0; v<m; v++){

//             // up
//             for(int i=0; i<v; i++){
//                 transition[v][m+i] = 1;
//             }

//             //down
//             for(int i=v+1; i<m; i++){
//                 transition[v+m][i] = 1;
//             }
//         }

//         long res[size][size] ;
//         res = power(transition,size,n-2);
//         long final[size] ;
//         final = multiply(res,base);

//         long ans = 0;

//         for(auto it: final){
//             ans = (ans + it)%mod;
//         }
        
//         return (int)ans;

//     }
// };

class Solution {
    const int mod = 1e9 + 7;
    // Defining a type alias makes the code much cleaner to read
    typedef vector<vector<long long>> Matrix;

public:
    // 1. Matrix Multiplication
    Matrix mul(const Matrix& a, const Matrix& b) {
        int size = a.size();
        // Initialize an empty matrix filled with 0s
        Matrix res(size, vector<long long>(size, 0));

        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                long long sum = 0;
                for(int k = 0; k < size; k++){
                    sum = (sum + (a[i][k] * b[k][j]) % mod) % mod;
                }
                res[i][j] = sum;
            }
        }
        return res;
    }

    // 2. Matrix Exponentiation
    Matrix power(Matrix a, int b) {
        int m = a.size();
        // Initialize an identity matrix (0s everywhere, 1s on diagonal)
        Matrix res(m, vector<long long>(m, 0));
        for(int i = 0; i < m; i++){
            res[i][i] = 1;
        }

        while(b > 0){
            if(b & 1){
                res = mul(res, a);
            }
            a = mul(a, a);
            b >>= 1;
        }
        return res;
    }

    // 3. Matrix * Vector Multiplication
    vector<long long> multiply(const Matrix& a, const vector<long long>& b) {
        int size = a.size();
        // Initialize result vector with 0s
        vector<long long> res(size, 0);

        for(int i = 0; i < size; i++){
            long long sum = 0;
            // Only 2 loops needed for Matrix * Vector
            for(int k = 0; k < size; k++){
                sum = (sum + (a[i][k] * b[k]) % mod) % mod;
            }
            res[i] = sum;
        }
        return res;
    }

    // 4. Main Function
    int zigZagArrays(int n, int l, int r) {
        // Edge case: If n < 2, n-2 will be negative and break the power function.
        // Adjust this depending on your problem's constraints.
        if (n == 1) return 0; 

        int m = r - l + 1;
        int size = 2 * m;

        // Base cases properly initialized
        vector<long long> base(size, 0);
        for(int i = 0; i < m; i++){
            base[i] = i;             // up
            base[i + m] = m - 1 - i; // down
        }

        // Transition matrix properly initialized to 0
        Matrix transition(size, vector<long long>(size, 0));

        for(int v = 0; v < m; v++){
            // up
            for(int i = 0; i < v; i++){
                transition[v][m + i] = 1;
            }
            // down
            for(int i = v + 1; i < m; i++){
                transition[v + m][i] = 1;
            }
        }

        // Perform exponentiation and multiplication
        Matrix resMatrix = power(transition, n - 2);
        vector<long long> finalVec = multiply(resMatrix, base);

        long long ans = 0;
        for(long long val : finalVec){
            ans = (ans + val) % mod;
        }
        
        return (int)ans;
    }
};