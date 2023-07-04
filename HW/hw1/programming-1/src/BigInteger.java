class BigInteger implements EasyInteger {
    // TODO define user specified fields
    // Warning 1: For Open and Close Principle, non-private fields are illegal.
    // Warning 2: References, arrays contain High-precision Numbers are illegal.
    //          For extension, all non-primitive or non-Number types are illegal.
    // Example for 1: public int len;(error) -> private int len;(correct)
    // Example for 2: java.math.BigInteger $233;(error) -> Number $233;(error) -> Object $233;(error)
    // Example for 2(extension): java.util.Vector $233;(error)
    // Example(primitive type): int[] num, nn[];(correct)
    // Example(primitive boxed in Number object): Integer[] num, nn[];(correct)

    /**
     * This constructor convert String to BigInteger.
     * @param s the input String, only contains character 0-9
     */
    private int[] ary = new int [5010];
    private int len = 0;
    private int maxlen = 0;
    private int flag = 0;
    BigInteger(final String s) {
        // TODO implements this constructor
        this.len = s.length();
        for (int i=0; i<this.len; i++){
            ary[5010-this.len+i] = s.charAt(i)-'0';
        }
    }
    /**
     * Calculate the value of (this + val).
     * This method don't change input arguments.
     * @param val The value to add to this
     * @return a new Integer whose value is (this + val)
     */
    @Override
    public EasyInteger add(final EasyInteger val) {
        final BigInteger v=(BigInteger) val;
        BigInteger result=null;
        // TODO let result <- this + v
        result = new BigInteger("");
        int lena = this.len;
        int lenb = v.len;
        int c = 0;
        this.maxlen = Math.max(lena, lenb);

        for(int i = 5009; i > 5009 - Math.max(lena, lenb); i--) {
            //int tmpa = (int)this.my_str.charAt(i)-48;
            //int tmpb = (int)v.my_str.charAt(i)-48;
            int tmp = this.ary[i] + v.ary[i] + c;
            c = tmp / 10;
            tmp %= 10;

            result.ary[i] = tmp;

        }
        if (c > 0){
            this.flag = 1;
            result.ary[5009 - Math.max(lena, lenb)] = c ;
        }
        result.maxlen = this.maxlen;
        result.flag = this.flag;
        //System.out.println(result.ary[0]);
        return result;
    }
    /**
     * Convert this to String.
     * @return the String representation of this
     */
    @Override
    public String toString() {
        final StringBuilder s=new StringBuilder();
        int start = 5010-this.maxlen, end = 5009;;
        //System.out.println(this.ary[0]);
        if (this.flag == 1){
            start--;
        }

        for (int i = start; i <= end; i++){
            //System.out.println("in"+this.ary[i-this.flag]);
            s.append(this.ary[i]);
            //System.out.println(s);
        }

        // TODO use s.append(...) to build the string
        return s.toString();
    }

    // TODO define user specified methods
}



