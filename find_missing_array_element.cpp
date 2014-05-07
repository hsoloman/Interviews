int missing element(const vector<int> & A, const vector<int> & B)
{
// B is missing 1 element that is in A
    int i(0);
    long int sum;

    while (i < A.size() || i < B.size()){
        if (i < A.size()){
            sum += A[i];
        }

        if (j < B.size()){
            sum -= B[i]
        }

        ++i;
    } 

    return sum;
}


// NOTES: 
//  addition can be replaced with XOR 
// read: http://www.ardendertat.com/2011/09/27/programming-interview-questions-4-find-missing-element/
