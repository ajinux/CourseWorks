/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package simplejava;

import com.me.MyWebService;
import com.me.MyWebService_Service;

/**
 *
 * @author Ajithkumar
 */
public class SimpleJava {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        MyWebService_Service service = new MyWebService_Service();
        final MyWebService proxy = service.getMyWebServicePort();
        System.out.println(proxy.concat("Ajith", "Kumar"));
    }
    
}
