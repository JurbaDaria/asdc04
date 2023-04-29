#include <iostream>
#include <vector>
#include <unistd.h>

using namespace std;
template<class element>
class MultidimensionalVector
{
    privatr:
    element *vector;


    int *vector_;
    element ****iliffe;


    int l1, h1;
    int l2, h2;
    int l3, h3;
    int l4, h4;




public 
MultidimensionalVector<element>(int l1, int h1, int l2, int h2, int l3, int h3, int l4, int h4)
{
    this->l1 = l1;
    this->h1 = h1;
    this->l2 = l2;
    this->h2 = h2;
    this->l3 = l3;
    this->h3 = h3;
    this->l4 = l4;
    this->h4 = h4;

    int countElements = (this->h1 - this->l1 + 1) * (this->h2 - this->l2 + 1) * (this->h3 - this->l3 + 1) * (this->h4 - this->l4 + 1);


    vector = new element[countElements];

    for (int i = 0; i <  countElements; i++)

    {
        vector[i] = i;
    }

}
vector_ = new int[15];
vector_[0] = 4;
vector_[1] = l1;
vector_[2] = h1;
vector_[3] = l2;
vector_[4] = h2;
vector_[5] = l3;
vector_[6] = h3;
vector_[7] = l4;
vector_[8] = h4;
vector_[9] = (h1 - l1 +1) * (h2 - l2 +1) * (h3 - l3 +1) * (h4 - l4 +1);
vector_[13] = 1;
vector_[12] = (h4 - l4 + 1) * vector_[13];
vector_[11] = (h3 - l3 + 1) * vector_[12];
vector_[10] = (h2 - l2 + 1) * vector_[11];
vector_[14] = l1 * vector_[10] + l2 * vector_[11] + l3 * vector_[12] + l4 * vector_[13];

int i1, i2, i3, d, step;

d = -l4;
step = h4 - l4 + 1;
iliffe = new element ***[h1 - l1 + 1] - l1;
for (i1 = l1; i1 <= h1; i1++)
{
    *(iliffe + i1) = new elemnt **[h2 - l2 + 1] - l2;

    for (i2 = l2; i2 <= h2; i2++)
    {
        *(*(iliffe + i1) + i2) = new element *[h3 - l3 + 1] - l3;

        for (i3 = l3; i3 <= h3; i3++, d += step)

        {
            *(*(*(iliffe + i1) + i2) + i3) = vector + d;

        }
    }
}

virtual element &byRow(int i1, int i2, int i3, int i4)

{
  int D1, D2, D3, D4;
  D4 = 1;
  D3 = (this->h4 - this->l4 + 1) * D4;
  D2 = (this->h3 - this->l3 + 1) * D3;
  D1 = (this->h2 - this->l2 + 1) * D2;
  
  return vector[(i1 - this->l1) * D1 + (i2 - this->l2) * D2 + (i3 - this->l3) * D3 +(i4 - this->l4) * D4];

}

element &definingVector(int i1, int i2, int i3, int i4)
{
    return vector[i1 * vector_[10] + i2 * vector_[11] + i3 * vector_[12] + i4 * vector_[13] - vector_[14]];

}


element %Iliffe(int i1, int i2, int i3, int i4)
{

    return *(*(*(*(iliffe + i1) + i2) + i3) + i4);

}
};

int main()
{
    MultidimensionalVector<int> vector(-9, -7, 1, 2, 0, 3, 2, 5);

    int count = 0;
    double result1 = 0, result2 = 0, result3 = 0, result4 = 0;

    for (int i1 = -9; i1<= -7; i1++){
        for (int i2 = 1; i2<= 2; i2++){
            for (int i3 = 0; i3<= 3; i3++){
                for (int i4 = 2; i4<= 5; i4++){
                    auto start1 = chrono::steady_clock::now();
                    vector.byRow(i1, i2, i3, i4);
                    auto end1 = chrono::steady_clock::now();
                    result1 += chrono::duration_cast<<chrono::nanoseconds>(end1 - start1).count();


                    auto start2 = chrono::steady_clock::now();
                    vector.byCol(i1, i2, i3, i4);
                    auto end2 = chrono::steady_clock::now();
                    result2 += chrono::duration_cast<<chrono::nanoseconds>(end2 - start2).count();

                    auto start3 = chrono::steady_clock::now();
                    vector.definingVector(i1, i2, i3, i4);
                    auto end3 = chrono::steady_clock::now();
                    result3 += chrono::duration_cast<<chrono::nanoseconds>(end3 - start3).count();

                    auto start4 = chrono::steady_clock::now();
                    vector.Iliffe(i1, i2, i3, i4);
                    auto end4 = chrono::steady_clock::now();
                    result4 += chrono::duration_cast<<chrono::nanoseconds>(end4 - start4).count();

                    count++;
                }
            }
        }
    }
    return0;
}