#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cmath>

using namespace std;

//const int MAX_FRAMES = 1000; 

int main()
{
    int nf=10, N, m;
    int no_tr = 0;

    srand(time(NULL));


    cout << "Enter the Bit size (m-bit): ";
    cin >> m;
    N = pow(2, m-1) ;

    cout << "Your window size is: " << N << endl;

    vector<int> frame(nf);
    vector<int> send(N);
    vector<int> receive(N);
    vector<int> acked(nf, 0); 

    int i = 0, k = 0, p = 0;

    while (i < nf)
    {
        int x = 0;

        for (int j = i; j < i + N && j < nf; j++)
        {
            int frame_loss = rand() % 2; 

            if (!frame_loss)
            {
                cout << "Sent Frame " << j + 1 << endl;
                send[k] = j + 1;
                no_tr++;
            }
            else
            {
                cout << "Frame " << j + 1 << "  is  Corrupted or lost " << endl;
                no_tr++;
            }

            k = (k + 1) % N;
        }

        for (int j = i; j < i + N && j < nf; j++)
        {
            int ack_loss = rand() % 2; 

            if (!ack_loss)
            {
                cout << "acknowledgment for Frame " << j + 1 << " received" << endl;
                acked[j] = 1; 
                receive[p] = j + 1;
                x++;
            }
            else
            {
                cout << "acknowledge for Frame " << j + 1 << " Not Received" << endl;
                cout << "Retransmitting Window" << endl;
                no_tr += x; 
                break;
            }

            p = (p + 1) % N;
        }

        if (i + N < nf)
        {
            cout << "Window slided" << endl;
        }

        i += x;
    }

    cout << "Total number of transmissions: " << no_tr << endl;

    return 0;
}
