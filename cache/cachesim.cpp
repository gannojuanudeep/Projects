#include <iostream>
#include <cmath>
#include <vector>
#include <sstream>
#include <bitset>
using namespace std;

class block
{
public:
    string tag = "";
    int validbit = 0;
    int LRUidx = -1;
    int dirtybit = 0;
    block()
    {
        string tag = "";
        int validbit = 0;
        int LRUidx = -1;
        int dirtybit = 0;
    }
};

class sets
{
public:
    vector<block> que = {};
    sets(int a)
    {
        que = vector<block>(a, block());
    }
};

int bintodec(string binary)
{
    int n = 0;
    int base = 1;
    for (int i = binary.size() - 1; i >= 0; i--)
    {
        if (binary[i] == '1')
        {
            n += base;
        }
        base *= 2;
    }
    return n;
}

int set_num(string s, vector<sets> &cache_vec, string tag1)
{
    int size = cache_vec.size();
    int a = bintodec(s);
    int k = a % size;
    return k;
}

string hit_or_miss(string s, vector<sets> &cache_vec, string tag1, int j)
{
    int idx = set_num(s, cache_vec, tag1);
    for (int i = 0; i < cache_vec[idx].que.size(); i++)
    {
        if (cache_vec[idx].que[i].tag == tag1 && cache_vec[idx].que[i].validbit == 1)
        {
            cache_vec[idx].que[i].LRUidx = j;
            return "HIT";
        }
    }
    return "MISS";
}

int LRU(vector<sets> &cache_vec, string set_1, string tag_1, int num_of_words, int j)
{

    int idx = set_num(set_1, cache_vec, tag_1);
    int min_idx = -1;
    int min_ele = 1e9;
    for (int i = 0; i < cache_vec[idx].que.size(); i++)
    {
        if (min_ele > cache_vec[idx].que[i].LRUidx)
        {
            min_idx = i;
            min_ele = cache_vec[idx].que[i].LRUidx;
        }
    }
    int l = 0;
    if (cache_vec[idx].que[min_idx].dirtybit == 1)
    {
        l = 1;
    }
    cache_vec[idx].que[min_idx].tag = tag_1;
    cache_vec[idx].que[min_idx].validbit = 1;
    cache_vec[idx].que[min_idx].dirtybit = 0;
    cache_vec[idx].que[min_idx].LRUidx = j;
    if (l == 1)
        return 200 * num_of_words;
    return 100 * num_of_words;
}

int FIFO(vector<sets> &cache_vec, string set_1, string tag_1, int num_of_words, int i)
{
    int idx = set_num(set_1, cache_vec, tag_1);
    block b = cache_vec[idx].que[0];
    cache_vec[idx].que.erase(cache_vec[idx].que.begin());
    int l = 0;
    if (cache_vec[idx].que[0].dirtybit == 1)
    {
        l = 1;
    }
    b.tag = tag_1;
    b.validbit = 1;
    b.dirtybit = 0;
    b.LRUidx = i;
    cache_vec[idx].que.push_back(b);
    if (l == 1)
        return 200 * num_of_words;
    return 100 * num_of_words;
}

int replace(vector<sets> &cache_vec, string s, string set_1, string tag_1, int num_of_words, int j, int t)
{
    int idx = set_num(set_1, cache_vec, tag_1);
    for (int i = 0; i < cache_vec[idx].que.size(); i++)
    {
        if (cache_vec[idx].que[i].validbit == 0)
        {
            cache_vec[idx].que[i].tag = tag_1;
            cache_vec[idx].que[i].validbit = 1;
            cache_vec[idx].que[i].LRUidx = j;
            return 100 * num_of_words;
        }
    }
    int k = 0;
    if (s == "lru")
    {
        k = LRU(cache_vec, set_1, tag_1, num_of_words, j);
    }
    else if (s == "fifo")
    {
        k = FIFO(cache_vec, set_1, tag_1, num_of_words, j);
    }
    return k;
}

vector<vector<string>> parse()
{
    vector<vector<string>> data = {};
    string line = "";
    while (getline(cin, line))
    {
        if (!line.empty())
        {
            string first_char = "";
            first_char += line[0];
            string characters = line.substr(4, 8);
            vector<string> line_data = {};
            line_data.push_back(first_char);
            line_data.push_back(characters);
            data.push_back(line_data);
        }
    }

    return data;
}

std::string hexToBinaryString(const std::string &hexString)
{
    unsigned int value = 0;
    std::stringstream ss;
    ss << std::hex << hexString;
    ss >> value;
    std::bitset<32> bits(value);
    string result = bits.to_string();
    return result;
}

void print_fun(int total_loads, int total_stores, int load_hits, int load_miss, int store_hits, int store_miss, int total_cycles)
{
    cout << "Total loads " << total_loads << endl;
    cout << "Total stores " << total_stores << endl;
    cout << "Load hits " << load_hits << endl;
    cout << "Load_misses " << load_miss << endl;
    cout << "Store hit " << store_hits << endl;
    cout << "Store misses " << store_miss << endl;
    cout << "Total cycles " << total_cycles << endl;
}

int main(int argc, char *argv[])
{
    // inputs
    int num_of_set = stoi(argv[1]);
    int num_of_blocks = stoi(argv[2]);
    int num_of_words = stoi(argv[3]) / 4;
    string LorF = string(argv[6]);
    string ag_4 = string(argv[4]);
    string ag_5 = string(argv[5]);
    // initi
    vector<sets> cache_vec(num_of_set, sets(num_of_blocks));
    int words_offset = 2 + log2(num_of_words);
    int set_bits = log2(num_of_set);
    int offset = words_offset;

    int load = 0;

    int load_hits = 0;
    int load_miss = 0;
    int total_loads = 0;
    int store_hits = 0;
    int store_miss = 0;
    int total_stores = 0;
    int total_cycles = 0;

    vector<vector<string>> data = parse();
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i][0] == "l")
        {
            load = 1;
        }
        else
        {
            load = 0;
        }
        string add = "";
        string set_1 = "";
        string tag_1 = "";
        add = data[i][1];
        add = hexToBinaryString(add);
        set_1 = add.substr(0, 32 - offset);
        tag_1 = set_1.substr(0, set_1.size() - set_bits);
        int idx = 0;
        idx = set_num(set_1, cache_vec, tag_1);
        string s = "";
        s = hit_or_miss(set_1, cache_vec, tag_1, i);

        if (load == 1)
        {
            total_loads += 1;
            if (s == "HIT")
            {
                load_hits += 1;
                total_cycles += 1;
            }
            else
            {
                load_miss += 1;
                int a = 0;
                a = replace(cache_vec, LorF, set_1, tag_1, num_of_words, i, 0);
                total_cycles += a + 1;
            }
        }
        else if (load == 0)
        {
            total_stores += 1;
            if (s == "HIT")
            {
                store_hits += 1;
                if (string(argv[5]) == "write-back")
                {
                    for (int j = 0; j < cache_vec[idx].que.size(); j++)
                    {
                        if (cache_vec[idx].que[j].tag == tag_1 && cache_vec[idx].que[j].validbit == 1)
                        {
                            cache_vec[idx].que[j].dirtybit = 1;
                            cache_vec[idx].que[j].LRUidx = i;
                            break;
                        }
                    }
                    total_cycles += 1;
                }
                else
                {
                    for (int j = 0; j < cache_vec[idx].que.size(); j++)
                    {
                        if (cache_vec[idx].que[j].tag == tag_1 && cache_vec[idx].que[j].validbit == 1)
                        {
                            cache_vec[idx].que[j].LRUidx = i;
                            break;
                        }
                    }
                    total_cycles += 101;
                }
            }
            else
            {
                store_miss += 1;
                if (ag_4 == "no-write-allocate")
                {
                    total_cycles += 100;
                }
                else
                {
                    int l = 0;
                    if (ag_5 == "write-back")
                    {
                        l = replace(cache_vec, LorF, set_1, tag_1, num_of_words, i, 1);
                        for (int j = 0; j < cache_vec[idx].que.size(); j++)
                        {
                            if (cache_vec[idx].que[j].tag == tag_1 && cache_vec[idx].que[j].validbit == 1)
                            {
                                cache_vec[idx].que[j].dirtybit = 1;
                                cache_vec[idx].que[j].LRUidx = i;
                                break;
                            }
                        }
                        total_cycles += l + 1;
                    }
                    else if (ag_5 == "write-through")
                    {
                        l = replace(cache_vec, LorF, set_1, tag_1, num_of_words, i, 0);
                        for (int j = 0; j < cache_vec[idx].que.size(); j++)
                        {
                            if (cache_vec[idx].que[j].tag == tag_1 && cache_vec[idx].que[j].validbit == 1)
                            {
                                cache_vec[idx].que[j].LRUidx = i;
                                break;
                            }
                        }
                        total_cycles += 100 * num_of_words + 101;
                    }
                }
            }
        }
    }
    print_fun(total_loads, total_stores, load_hits, load_miss, store_hits, store_miss, total_cycles);
}