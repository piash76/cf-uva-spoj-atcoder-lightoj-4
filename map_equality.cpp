
#include <utility>
#include <algorithm>
#include <string>
#include <iostream>
#include <map>

template <typename Map>
bool map_compare (Map const &lhs, Map const &rhs) {
    // No predicate needed because there is operator== for pairs already.
    return lhs.size() == rhs.size()
        && std::equal(lhs.begin(), lhs.end(),
                      rhs.begin());
}

int main () {
    using namespace std;

    map<string,string> a, b;

    a["Foo"] = "0";
    a["Bar"] = "1";
    a["Frob"] = "2";

    b["Foo"] = "1";
    b["Bar"] = "1";
    b["Frob"] = "2";

    if(equal(a.begin(),a.end(),b.begin())) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    /*cout << "a == b? " << map_compare (a,b) << " (should be 1)\n";
    b["Foo"] = "1";
    cout << "a == b? " << map_compare (a,b) << " (should be 0)\n";

    map<string,string> c;
    cout << "a == c? " << map_compare (a,c)  << " (should be 0)\n";*/
}
