#include <vector>
using std::vector;
//search-a-2d-matrix

bool searchMatrix(vector<vector<int> > &matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) return false;
    int low = 0;
    int high = matrix.size();
    int back = matrix[0].size()-1;
    int mid;
    while (low < high) {
        mid = (low + high)/2;
        if (matrix[mid][back] == target) { return true; 
        } else if (matrix[mid][back] < target) {
            low = mid+1;
        } else {
            high = mid;
        }
    }
    printf("idx=%d\n", low);
    if (low+1 > matrix.size()) return false;
    int idx = low;
    low = 0;
    high = matrix[idx].size();
    while (low < high) {
        printf("low=%d high=%d\n", low, high);
        mid = (low + high)/2;
        if (matrix[idx][mid] == target) { return true;
        } else if (matrix[idx][mid] < target) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return false;
}

bool searchMatrix2(vector<vector<int> > &matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) return false;
    int col = matrix[0].size();
    int low = 0;
    int high = matrix.size() * col;
    int mid;
    while (low < high) {
        mid = (low + high)/2;
        printf("low=%d high=%d\n", low, high);
        if (matrix[mid/col][mid%col] == target) {
            return true;
        } else if (matrix[mid/col][mid%col] < target) {
            low = mid + 1; 
        } else {
            high = mid;
        }
    }
    return false;
}

int main()
{
    vector<vector<int> > vv = {{1,3,5,7},{10,11,16,20},{23,30,34,50} }; 
        //{1,3} };   1
        //{1,3,5,7},{10,11,16,20},{23,30,34,50} };   11
        //{ {1}, {3} } , 4
    printf("%d\n", searchMatrix2(vv, 11));
    return 0;
}
