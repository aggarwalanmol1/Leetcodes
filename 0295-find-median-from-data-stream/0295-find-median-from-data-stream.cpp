class MedianFinder {
private:
    priority_queue<int> left;  // max heap
    priority_queue<int, vector<int>, greater<int>> right;  // min heap

public:
    MedianFinder() {
    }

    void addNum(int num) {
        // Put the number into the left half
        left.push(num);

        // Make sure left's largest <= right's smallest
        if (!right.empty() && left.top() > right.top()) {
            right.push(left.top());
            left.pop();
        }

        // Balance the sizes
        if (left.size() > right.size() + 1) {
            right.push(left.top());
            left.pop();
        }

        if (right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        }
    }

    double findMedian() {
        if (left.size() > right.size()) {
            return left.top();
        }

        return (left.top() + right.top()) / 2.0;
    }
};