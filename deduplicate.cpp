#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<iterator>

using namespace std;

vector<string> distinct(vector<string>& vec)
{
    // First sort words alphabetically so we can find the duplicates.
    sort(begin(vec), end(vec));

    // Unique algorithm rearranges the input range to "mark for deletion"
    // adjacent duplicated entries and return iterator that
    // denotes the end of the range of the unique values
    auto end_unique = unique(begin(vec), end(vec));
    // then remove the nonunique elements
    vec.erase(end_unique, end(vec));
    return vec;
}

int main(int argc, const char * argv[]) {

    vector<string> words {"car", "apple", "box", "car", "apple", "foo"};
    // remove dups
    vector<string> res=distinct(words);

    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    cout<<"\n";

    return 0;
}
