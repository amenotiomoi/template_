namespace rsort {
   // only unsigned number
   #define tT template<typename T> inline
   typedef unsigned int ui;
   tT unsigned char getByte(const T& num, unsigned int bi) {
      return reinterpret_cast<const unsigned char*>(&num)[bi];
   }
   const ui BUCKET_SIZE=256;
   ui c[BUCKET_SIZE]={0};
   tT void sort(T*a,T*o,ui n) {
      for(ui i=0;i<BUCKET_SIZE;++i) c[i]=0;
      for(ui bi=0;bi<sizeof(T);++bi) {
         for(ui i=0;i<n;++i) c[getByte(a[i],bi)]++;
         for(ui i=1;i<BUCKET_SIZE;++i) c[i]+=c[i-1];
         for(ui i=n-1;i<n;--i) o[--c[getByte(a[i],bi)]]=a[i];
         swap(a,o);
         memset(c,0,BUCKET_SIZE*sizeof(ui));
      }
      if(sizeof(T)%2==1) memcpy(o,a,n*sizeof(T));
   }
   tT void sort(T*a,ui n) {
      T *o=(T*)malloc(n*sizeof(T));
      sort(a,o,n);
      free(o);
   }
   tT void sort(T*s,T*e) {
      sort(s,e-s);
   }
   tT void sort(std::vector<T> &Q) {
      sort(Q.data(),Q.size());
   }
   #undef tT
}
