# 언제 풀었는지 모르겠는데 옛날에 푼듯하네요!!!!

#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
map<string, int> genre_p;
bool comp(vector<string> a, vector<string> b) {
    map<string, int>::iterator it_a, it_b;
    it_a = genre_p.find(a[0]);
    it_b = genre_p.find(b[0]);
    
    if (it_a->second == it_b->second) {
        if (stoi(a[1]) == stoi(b[1]))
            return stoi(a[2]) < stoi(b[2]);
        else
            return stoi(a[1]) > stoi(b[1]);
    }
    else
        return it_a->second > it_b->second;
    
}

vector<string> make_vector(string genre, int play, int i) {
    vector<string> new_vec = {genre, to_string(play), to_string(i)};
    return new_vec;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    vector<vector<string>> musics;
    map<string, int>::iterator it;
    
    int i, n = genres.size();
    for (i = 0; i < n; i++) {
        it = genre_p.find(genres[i]);
        if (it == genre_p.end()) {
            genre_p.insert(make_pair(genres[i], plays[i]));
        }
        else {
            it->second += plays[i];
        }
        
        musics.push_back(make_vector(genres[i], plays[i], i));
    }
    
    sort(musics.begin(), musics.end(), comp);
    
    int cmp;
    for (i = 0; i < n; i++) {
        if (i >= 2) {
            if (musics[i][0] == (musics[i-2][0]))
                continue;
        }
        answer.push_back(stoi(musics[i][2]));
    }
    
    return answer;
}
