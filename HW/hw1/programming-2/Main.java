import java.util.Arrays;
import java.util.Scanner;


public class Main {
    private static int[][] sudoku;
    private static int n = 0, m = 0;

    public static void main(final String... arg){
        try (final Scanner cin = new Scanner(System.in)) {
            n = cin.nextInt();
            m = n * n;
            sudoku = new int[m][m];
            for (int i = 0; i < m; i++){
                for (int j = 0; j < m; j++){
                    sudoku[i][j] = cin.nextInt();
                    //System.out.println("i "+i+" j "+j+" "+sudoku[i][j]);
                }
            }
        }
        if (sub_matrix()){
            if (col_row()){
                System.out.println("yes");
            }
            else {
                System.out.println("no");
            }
        }
        else {
            System.out.println("no");
        }
    }

    public static boolean col_row(){
        boolean[] cflag = new boolean[m+1];
        boolean[] rflag = new boolean[m+1];

        for (int i = 0; i < m; i++){
            for (int j = 0; j < m; j++){
                int ctmp = sudoku[i][j];
                int rtmp = sudoku[j][i];

                if (!cflag[ctmp]){
                    cflag[ctmp] = true;
                }
                else {
                    return false;
                }

                if (!rflag[rtmp]){
                    rflag[rtmp] = true;
                }
                else {
                    return false;
                }
            }
            Arrays.fill(cflag,false);
            Arrays.fill(rflag,false);
        }
        return true;
    }

    public static boolean sub_matrix(){
        boolean[] flag = new boolean[m+1];
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){

                for (int subi = i * n; subi < i * n + n; subi++){
                    for (int subj = j * n; subj < j * n + n; subj++){
                        int tmp = sudoku[subi][subj];

                        if (!flag[tmp]){
                            flag[tmp] = true;
                        }
                        else {
                            return false;
                        }

                    }
                }
                Arrays.fill(flag,false);
            }
        }
        return true;
    }




}


