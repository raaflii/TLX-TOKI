    #include <iostream>
    #include <cmath>
    #include <list>

    using namespace std;

    bool isPrima(int bil) {
        if (bil == 0 || bil == 1) {
            return false;
        }

        for(int i = 2; i <= floor(sqrt(bil)); i++) {
            if (bil % i == 0) {
                return false;
            }
        }
        return true;
    }

    list<int> bilPrima(int n) {
        list<int> prima;

        for(int i = 2; i < n; i++) {
            if (isPrima(i) == 1) {
                prima.push_back(i);
            }
        }

        return prima;
    }

    int main() {

        int N;
        cin >> N;

        if (isPrima(N) == 1) {
            cout << N;
            return 0;
        }

        list<int> prima = bilPrima(N);
        list<int> result;

        while (true) {
            if (N % prima.front() != 0) {
                prima.pop_front();
            } else { 
                result.push_back(prima.front());
                N /= prima.front();

                if (prima.size() == 0 or N == 1) {
                    int curr = result.front();
                    int count = 0;

                    for (int a : result) {
                        if (a == curr) {
                            count++;
                        } else {
                            cout << curr;
                            if (count > 1) {
                                cout << "^" << count;
                            }
                            cout << " x ";
                            count = 1;
                        }

                        curr = a;
                    }

                    cout << curr;
                    if (count > 1) {
                        cout << "^" << count;
                    }

                    break;
                }
            }
        }
        
        return 0;
    }