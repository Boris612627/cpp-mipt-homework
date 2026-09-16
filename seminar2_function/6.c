int trib(int a){
        int tr0 = 0;
        int tr1 = 0;
        int tr2 = 1;
        int tr;
        if(a == 0) return 0;
        if(a == 1) return 0;
        if(a == 2) return 1;
        for(int i = 3; i <= a; i++){
                tr = tr2 + tr1 + tr0;
                tr0 = tr1;
                tr1 = tr2;
                tr2 = tr;
}
        return tr;
}

int main(){
        int n;
        scanf("%i", &n);
        printf("%i", trib(n));
}

