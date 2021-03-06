//
// Created by ward_s on 19/02/18.
//

#ifndef SPINW_SW_STRUCTS_H
#define SPINW_SW_STRUCTS_H

typedef struct lattice {
    double angle[3];
    double lat_const[3];
    double sym[3][4][100]; // We have up to 100 symmetry operations..
    double origin[3];
    char* label;
    int nSymOp;
} lattice;

typedef struct unit_cell{
    double r[3][100];// We have up to 100 atoms in the unit cell..
    double S[100];
    char** label;
    int color[3][100];
    double ox[100];
    double occ[100];
    double b[2][100];
    double ff[2][11][100];
    int A[100];
    int Z[100];
    double biso[100];
    int nAtom;
} unit_cell;

typedef struct twin {
    double vol[10]; // We have up to 10 twins
    double rotc[3][3][10];
    int nTwin;
} twin;

typedef struct matrix{
    double mat[3][3][100]; // Up to 100 magnetic atoms
    int color[3][100];
    char** label;
    int nMat;
} matrix;

typedef struct single_ion{
    int aniso[100];
    int g[100];
    double field[3];
    double T;
    int nMagAtom;
} single_ion;

typedef struct coupling{
    int dl[3][2000];
    int atom1[1000];
    int atom2[1000];
    int mat_idx[3][1000];
    int idx[1000];
    int type[3][1000];
    int sym[3][1000];
    double rdip;
    int nsym;
    int nBond;
} coupling;

typedef struct mag_str{
    double F_real[3][1000][10];
    double F_imag[3][1000][10];
    double k[3][10];
    int nExt[3];
    int nMagExt;
    int nK;
} mag_str;

typedef struct unit{
    double kB;
    double muB;
    double mu0;
    char** label;
    double nformula;
    double qmat[3][3];
}unit;

typedef struct spinwave_opt{
    bool notwin;
    bool sortMode;
    int optmem;
    float toll;
    bool hermit;
    float omega_toll;
    double formfact;
    bool gtensor;
    bool cmplxBase;
    int tid;
    int fid;

    // We can not initialise in C but can in c++
# ifdef __cplusplus
    spinwave_opt(): notwin(false), sortMode(true), optmem(0), toll(1e-4),
                    hermit(true), omega_toll(1e-5), formfact(false),
                    gtensor(false),cmplxBase(false), tid(-1), fid(-1) {}

#endif
}spinwave_opt;

typedef struct SS{
    double iso;
    double ani;
    double dm;
    double gen;
    double bq;
    double dip;

}SS;

typedef struct SI{
    double aniso;
    double g;
    double field;
}SI;

typedef struct init_matrix{
    struct SS SS;
    struct SI SI;
    double RR[100][100];
}init_matrix;

typedef struct matom_struct{
    double r[3][100];
    int idx[100];
    double S[100];
    int nMatom;

}matom_struct;

#endif //SPINW_SW_STRUCTS_H
