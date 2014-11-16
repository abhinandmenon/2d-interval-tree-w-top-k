
#include <mdds/segment_tree.hpp>
#include <string>
#include <iostream>

using namespace std;

typedef ::mdds::segment_tree<long, string> db_type;

struct string_printer : public unary_function<string*, void>
{
    void operator() (const string* p) const
    {
        cout << "search hit: " << *p << endl;
    }
};

int main()
{
    db_type db;
    string A("Aa");
    string B("Bb");
    string C("Cc");

    string D("Dd");

    // Insert data into the tree.
    db.insert(0,  10, &A);
    db.insert(2,  20, &B);
    db.insert(9, 15, &C);

    // Don't forget to build it before calling search().
    db.build_tree();

    db.insert(4, 25, &D);

    // Don't forget to build it before calling search().
    db.build_tree();

    // Run search and get the result.
    db_type::search_result result = db.search(9);

    // Print the result.
    cout << "result size: " << result.size() << endl;
    for_each(result.begin(), result.end(), string_printer());
}

