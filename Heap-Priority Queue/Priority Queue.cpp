// Max heap
priority_queue<int>pq;
// here default comparison operator is less<int> because max heap sorts in increasing order
// Largest element is poped out and placed at the end of the error

// Min heap
priority_queue<int,vector<int>,greater<int>>pq;

class Person {
    public:
        int age;
    
        float height;
    
        Person(int age, float height)
            : age(age), height(height)
        {
        }
};

// less than operator overloading required if we want to create a max heap
bool operator<(const Person& p1, const Person& p2)
{
    return p1.height < p2.height;
}

// greater than operator overloading required if we want to create a min heap
bool operator>(const Person& p1, const Person& p2)
{
    return p1.height > p2.height;
}