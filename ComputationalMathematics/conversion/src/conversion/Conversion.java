
package conversion;

import javax.swing.JOptionPane;

/**
 *
 * @author Camila Sales
 */
public class Conversion {

    public static void main(String[] args) {
        String base = JOptionPane.showInputDialog("Informe a base original");        
        String numb = JOptionPane.showInputDialog("Informe o número");
        String baseX = JOptionPane.showInputDialog("Informe a base para conversão");

        if(base.equals("10")){
            System.out.println("O número "+numb+"(base "+base+")"+" convertido para a base"+baseX
                    +" é:"+convert10ToX(Integer.parseInt(numb), Integer.parseInt(baseX)));
        }else{
            int convertido = convertXTo10(numb,  Integer.parseInt(base));
            System.out.println(convertido);
            if(baseX.equals("10")){
               System.out.println("O número "+numb+"(base "+base+")"+" convertido para a base"
                       +baseX+" é:"+convertido);
                
            }else{
                System.out.println("O número "+numb+"(base "+base+")"+" convertido para a base"
                        +baseX+" é:"+convert10ToX(convertido,  Integer.parseInt(baseX)));

            }
            
        }

    }

    public static String convert10ToX(int numb, int baseX) {
        /*
        O número decimal será dividido 
        sucessivas vezes pela base, o resto de cada divisão ocupará sucessivamente as 
        posições de ordem 0, 1, 2 e assim por diante, até que o resto da última divisão 
        (que resulta em quociente 0) ocupe a posição de mais alta ordem.
         */
        String convertido = "";
        if (numb==0){return "0";}
        while(numb > 0) {
            convertido = (numb % baseX) + convertido;
            numb /= baseX;
        }
        return convertido;
    }
    
    public static int convertXTo10(String numb, int base){
        /*
        Nb = a0 × bn + a1 × bn-1 + … + an × b0
        A melhor forma de fazer a conversão é usando essa expressão. Como exemplo,
        o número 1011012 terá calculado seu valor na base 10:
        1011012 = 1×25 + 0×24 + 1×23 + 1×22 + 0×21 + 1×20 = 4510
        */
        int sum = 0;
        int size = numb.length();
        char c;
        for(int i = 0; i < size; i++){
            c = numb.charAt(i);
            if (c == '0') continue;
            sum += Math.pow(base, (size-(i+1)));
        }
        return sum;
    }

}
