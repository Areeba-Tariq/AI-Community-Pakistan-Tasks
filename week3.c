#include <iostream>
using namespace std;

int main() {
    int unitsConsumed[3][3] = {
        {50, 100, 25},
        {110, 150, 200},
        {220, 210, 300}
    };
    int option = 1;
    while (option == 1 || option == 2) {
        cout << "\nMy Student Id is X123 \n" << "Press 1" <<
                " to display slab1 and slab2\nPress 2 to display " <<
                "slab3\nPress any Key to exit" << endl;
        int input;
        cin >> input;
        switch (input) {
            case 1: {
                int ans[3];
                int ans1[3];
                for (int i = 0; i < 3; i++) {
                    ans[i] = unitsConsumed[0][i] * 10;
                }
                for (int i = 0; i < 3; i++) {
                    ans1[i] = unitsConsumed[1][i] * 15;
                }
                cout << "The Bill for slab 1 is" << endl;
                for(int i=0;i<3;i++)
                {
                    cout << ans[i] << " ";
                }
                cout << "\nThe Bill for slab 2 is" << endl;
                for(int i=0;i<3;i++)
                {
                    cout << ans1[i] << " ";
                }
                option = 1;
                break;
            }
            case 2: {
                int ans2[3];
                for (int i = 0; i < 3; i++) {
                    ans2[i] = unitsConsumed[2][i] * 20;
                }
                option = 2;
                cout << "\nThe Bill for slab 3 is" << endl;
                for(int i=0;i<3;i++)
                {
                    cout << ans2[i] << " ";
                }
                break;
            }
            default:
                option = 3;
        }
    }
    return 0;
}


