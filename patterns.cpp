#include "iostream"
using namespace std;

void pyramid(int n) {
    for (int i = 1;i <= n;i++) {
        //Spaces
        for (int j = 1;j <= n - i;j++)
            cout<<"  ";
        //Print *'s
        for (int j = 1;j <= (2 * i - 1);j++)
            cout<<"* ";
        cout<<endl;
    }

    for (int i = 0;i < n;i++) {
        for (int j = 0;j < i;j++)
            cout<<"  ";
        for (int j = 1;j <= (2 * (n - i) - 1);j++)
            cout<<"* ";
        cout<<endl;
    }
    cout<<endl;
}

void hollow_pyramid(int n) {
    for (int i = 1;i < n;i++) {
        for (int j = 1;j <= n - i;j++)
            cout<<"* ";
        for (int j = 1;j <= (2 * i - 1);j++)
            cout<<"  ";
        for (int j = 1;j <= n - i;j++)
            cout<<"* ";
        cout<<endl;
    }

    for (int i = 1;i < n;i++) {
        for (int j = 1;j <= i;j++)
            cout<<"* ";
        for (int j = 1;j <= (2 * (n - i) - 1);j++)
            cout<<"  ";
        for (int j = 1;j <= i;j++)
            cout<<"* ";
        cout<<endl;
    }
    cout<<endl;
}

int main() {
    int n;
    cout<<"Enter n value: ";
    cin>>n;

    // 1
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++)
            cout<<"* ";
        cout<<endl;
    }
    cout<<endl;
    //2
    for(int i=0;i<n;i++) {
        for(int j=0;j<i+1;j++)
            cout<<"* ";
        cout<<endl;
    }
    cout<<endl;

    //3
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=i;j++)
            cout<<j<<" ";
        cout<<endl;
    }
    cout<<endl;

    //4
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=i;j++)
            cout<<i<<" ";
        cout<<endl;
    }
    cout<<endl;

    //5
    for(int i=1;i<=n;i++) {
        for (int j = n;j >= i; j--) {
            cout<<"* ";
        }
        cout<<endl;
    }
    cout<<endl;

    //6
    for(int i=0;i<n;i++) {
        for(int j=1;j<=n-i;j++)
            cout<<j<<" ";
        cout<<endl;
    }
    cout<<endl;

    //7
    for (int i = 1;i <= n;i++) {
        //Spaces
        for (int j = 1;j <= n - i;j++)
            cout<<"  ";
        //Print *'s
        for (int j = 1;j <= (2 * i - 1);j++)
            cout<<"* ";
        cout<<endl;
    }
    cout<<endl;

    //8
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < i;j++)
            cout<<"  ";
        for (int j = 1;j <= (2 * (n - i) - 1);j++)
            cout<<"* ";
        cout<<endl;
    }
    cout<<endl;

    //9


    //10
    bool flag = true;
    for (int i = 0;i < n;i++) {
        if (i % 2 == 0)
            flag = true;
        else
            flag = false;
        for (int j = 0;j <= i;j++) {
            cout<<flag<<" ";
            flag = !flag;
        }
        cout<<endl;
    }
    cout<<endl;

    //11
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n-i;j++)
            cout<<"  ";
        for(int j = 1;j <= i;j++)
            cout<<j<<" ";
        for(int j = i - 1;j >= 1;j--)
            cout<<j<<" ";
        cout<<endl;
    }

    cout<<endl;
    //12
    int start = 1;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= i;j++) {
            cout<<start<<" ";
            start++;
        }
        cout<<endl;
    }
    cout<<endl;

    //13
    for (int i = 1;i <= n;i++) {
        char ch = 'A';
        for (int j = 1;j <= i;j++) {
            cout<<ch<<" ";
            ch++;
        }
        cout<<endl;
    }
    cout<<endl;

    //14
    for (int i = 0;i < n;i++) {
        char ch = 'A';
        for (int j = 0;j < n - i;j++) {
            cout<<ch<<" ";
            ch++;
        }
        cout<<endl;
    }
    cout<<endl;

    //15
    char c = 'A';
    for (int i = 0;i < n;i++) {
        for (int j = 0;j <= i;j++)
            cout<<c<<" ";
        c++;
        cout<<endl;
    }
    cout<<endl;

    //16
    for (int i = 1;i <= n;i++) {
        char ch = 'A';
        for (int j = 1;j <= n - i;j++)
            cout<<"  ";
        for (int j = 1;j <= i;j++) {
            cout<<ch<<" ";
            ch++;
        }
        ch--;
        for (int j = i - 1;j >= 1;j--) {
            ch--;
            cout<<ch<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    //17
    for (int i = 1;i <= n;i++) {
        char ch = n + 'A';
        for (int j = 1;j <= i;j++)
            ch--;
        for (int j = 1;j <= i;j++) {
            cout<<ch<<" ";
            ch++;
        }
        cout<<endl;
    }
    cout<<endl;

    //18
    for (int i = 1;i <= n;i++) {
        if (i == 1 || i == n) {
            for (int j = 1;j <= n;j++)
                cout<<"* ";
            cout<<endl;
        }
        else {
            cout<<"*";
            for (int j = 1;j <= n - 2;j++)
                cout<<"  ";
            cout<<" *"<<endl;
        }
    }
    cout<<endl;

    pyramid(n);
    hollow_pyramid(n);

    //19
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= i;j++)
            cout<<j<<" ";
        for (int j = 1;j <= 2 * (n - i);j++)
            cout<<"  ";
        for (int j = i;j >= 1;j--)
            cout<<j<<" ";
        cout<<endl;
    }
    cout<<endl;

    //20
    int size = 2 * n - 1;  // The size of the square matrix

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            // The value decreases as we move towards the center
            int value = n - min(min(i, j), min(size - 1 - i, size - 1 - j));
            cout << value << " ";
        }
        cout << endl;
    }

    return 0;
}


