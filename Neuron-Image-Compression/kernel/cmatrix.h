#ifndef CMatrix_H
#define CMatrix_H
#include <vector>
#include <cstddef>
#include "carray.h"
#include "cvector.h"

#ifdef QT_VERSION
class QDebug;
class QDataStream;
#endif
class CRealRange;

namespace CGL {

class CMatrix
{
public:
    typedef double T;
private:
    typedef std::vector<T> Data;
    typedef std::vector<T*> Pointers;


    Data data;
    Pointers m;
    int wid;
    void repoint();

    CMatrix dotTranspose() const;
public:
    CMatrix();
    CMatrix(int w, int h);
    CMatrix(const CMatrix&);

    void resize(int w, int h);

    CMatrix& operator =(const CMatrix &);

    T* operator [](int r) { return m[r]; }
    const T* operator [](int r) const { return m[r]; }

    T minInRow(int r) const;
    T minInColumn(int c) const;
    T minInRowExclude(int r, int exclude) const;
    T minInColumnExclude(int c, int exclude) const;
    T max() const;
    CRealRange estimateRange() const;
    void plusInRow(int r, const T& val);
    void plusInColumn(int c, const T& val);
    void excludeRow(int r);
    void excludeColumn(int c);


    CMatrix pseudoInvers() const;
    CMatrix invers() const;
    CMatrix transpose() const;
    CMatrix operator* (const CMatrix&) const;
    CMatrix operator* (const CVector& vector) const;
    T det();
    void naNtoInf();

    int width() const { return wid; }
    int height() const { return m.size(); }
    int size() const { return data.size(); }
    bool empty() const { return data.empty(); }

#ifdef QT_VERSION
    friend QDebug operator<< (QDebug out, const CMatrix &obj);

    friend QDataStream& operator<< (QDataStream&, const CMatrix&);
    friend QDataStream& operator>> (QDataStream&, CMatrix&);
#endif
};

CMatrix operator* (const CVector&, const CMatrix&);
#ifdef QT_VERSION
QDataStream& operator<< (QDataStream&, const CMatrix&);
QDataStream& operator>> (QDataStream&, CMatrix&);

QDebug operator<< (QDebug out, const CMatrix &obj);
#endif

}

#endif // CMatrix_H
