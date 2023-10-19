#include<iostream>
using namespace std;
#include <list>
#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

int fifo(vector<int> page_references, int frame_count) {
    queue<int> memory;
    unordered_set<int> memory_set;
    int page_faults = 0;

    for (int page : page_references) {
        if (memory_set.find(page) == memory_set.end()) {
            if (memory.size() < frame_count) {
                memory.push(page);
                memory_set.insert(page);
            } else {
                int page_to_replace = memory.front();
                memory.pop();
                memory_set.erase(page_to_replace);
                memory.push(page);
                memory_set.insert(page);
                page_faults++;
            }
        }

        cout << "Page References: " << page << endl;
        cout << "Memory: ";
        for (int p : memory_set) {
            cout << p << " ";
        }
        cout << endl;
    }

    return page_faults;
}
int optimal(vector<int> page_references, int frame_count) {
    list<int> memory;
    unordered_map<int, list<int>::iterator> memory_map;
    int page_faults = 0;

    for (int i = 0; i < page_references.size(); i++) {
        int page = page_references[i];
        if (memory_map.find(page) == memory_map.end()) {
            if (memory.size() >= frame_count) {
                int farthest_occurrence = -1;
                int page_to_replace;

                for (auto it = memory.begin(); it != memory.end(); ++it) {
                    int current_page = *it;
                    int next_occurrence = -1;

                    for (int j = i + 1; j < page_references.size(); j++) {
                        if (page_references[j] == current_page) {
                            next_occurrence = j;
                            break;
                        }
                    }

                    if (next_occurrence == -1) {
                        page_to_replace = current_page;
                        break;
                    }

                    if (next_occurrence > farthest_occurrence) {
                        farthest_occurrence = next_occurrence;
                        page_to_replace = current_page;
                    }
                }

                memory_map.erase(page_to_replace);
                memory.remove(page_to_replace);
            }

            memory.push_front(page);
            memory_map[page] = memory.begin();
            page_faults++;
        }

        cout << "Page References: " << page << endl;
        cout << "Memory: ";
        for (int p : memory) {
            cout << p << " ";
        }
        cout << endl;
    }

    return page_faults;
}
int lru(vector<int> page_references, int frame_count) {
    list<int> memory;
    unordered_map<int, list<int>::iterator> memory_map;
    int page_faults = 0;

    for (int page : page_references) {
        if (memory_map.find(page) == memory_map.end()) {
            if (memory.size() >= frame_count) {
                int least_recently_used = memory.back();
                memory_map.erase(least_recently_used);
                memory.pop_back();
            }

            memory.push_front(page);
            memory_map[page] = memory.begin();
            page_faults++;
        } else {
            memory.splice(memory.begin(), memory, memory_map[page]);
        }

        cout << "Page References: " << page << endl;
        cout << "Memory: ";
        for (int p : memory) {
            cout << p << " ";
        }
        cout << endl;
    }

    return page_faults;
}

int main() {
    vector<int> page_references;
    cout<<"Enter the input and write -1 to stop: "<<endl;
    int c;
    cin>>c;
    while(c>=0){
    	page_references.push_back(c);
    	cin>>c;
	}
    int frame_count = 3;
    
    cout<<"Give which page replacement : \n1.FIFO\n2.LRU\n3.Optimal";
    cin>>c;
    if(c==1){
	
    cout<<"\n====================FIFO==========================\n\n";

    int page_faults = fifo(page_references, frame_count);
    

    cout<< "=-=-=-=->>    Total Page Faults: " << page_faults <<endl;
    
}
    else if(c==2){
	
    cout<<"\n===================Least Recently Used===========================\n\n";
    
    int page_faults = lru(page_references,frame_count);
    
    cout << "=-=-=-=->>    Total Page Faults: " << page_faults << endl;
}
 else if (c==3){
 	cout<<"\n===================Optimal===========================\n\n";
    
   int page_faults = optimal(page_references,frame_count);
    
    cout << "=-=-=-=->>    Total Page Faults: " << page_faults << endl;
 }
    return 0;
}

