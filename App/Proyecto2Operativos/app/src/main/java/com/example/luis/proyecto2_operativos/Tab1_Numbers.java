package com.example.luis.proyecto2_operativos;

/**
 * Created by luis on 13/11/2017.
 */
import android.app.Activity;
import android.support.v4.app.Fragment;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.TextView;
import java.util.Random;
import android.widget.Toast;
import android.os.Handler;
import android.util.Log;


public class Tab1_Numbers extends Fragment{
    private static final String TAG = "Tab1_Numbers";
    TextView pin_number;
    TextView input_pin_number;
    int numeroRandom = 0;
    int numero_input =0;

    private int[] button_list;

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        View rootView = inflater.inflate(R.layout.tab1_numbers, container, false);
        input_pin_number = rootView.findViewById(R.id.input_pin_number);
        pin_number = (TextView)rootView.findViewById(R.id.pin_number);
        button_list = new int[]{R.id.button_0,R.id.button_1,R.id.button_2,R.id.button_3,R.id.button_4,R.id.button_5,R.id.button_6,R.id.button_7,R.id.button_8,R.id.button_9,R.id.button_ent};

        for(int i = 0; i < button_list.length; i++){
            Button button = (Button)rootView.findViewById(button_list[i]);
            button.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View view) {
                    setInput(view.getId());
                }
            });
        }

        setPIN();
        return rootView;
    }

    private void setInput(int button_id){
        switch (button_id){
            case R.id.button_0:
                numero_input = (numero_input*10) + 0;
                break;
            case R.id.button_1:
                numero_input = (numero_input*10) + 1;
                break;
            case R.id.button_2:
                numero_input = (numero_input*10) + 2;
                break;
            case R.id.button_3:
                numero_input = (numero_input*10) + 3;
                break;
            case R.id.button_4:
                numero_input = (numero_input*10) + 4;
                break;
            case R.id.button_5:
                numero_input = (numero_input*10) + 5;
                break;
            case R.id.button_6:
                numero_input = (numero_input*10) + 6;
                break;
            case R.id.button_7:
                numero_input = (numero_input*10) + 7;
                break;
            case R.id.button_8:
                numero_input = (numero_input*10) + 8;
                break;
            case R.id.button_9:
                numero_input = (numero_input*10) + 9;
                break;
            case R.id.button_ent:
                compareNumbers();
                break;
        }
        input_pin_number.setText(numero_input+"");
    }

    private void compareNumbers(){
        String mensaje = "PIN Incorrecto";
        if(numeroRandom == numero_input){
            mensaje = "PIN Correcto";
            setPIN();
        }
        Log.v(TAG,"NR " + numeroRandom + " input " +numero_input);
        Toast.makeText(this.getContext(), mensaje, Toast.LENGTH_SHORT).show();
        resetInput();
    }

    private void setPIN(){
        Random rn = new Random();
        int range = 999999 - 100000 + 1;
        numeroRandom =  rn.nextInt(range) + 100000;
        pin_number.setText(numeroRandom+"");
    }

    private void resetInput(){
        numero_input = 0;
        input_pin_number.setText(numero_input+"");
    }

}
