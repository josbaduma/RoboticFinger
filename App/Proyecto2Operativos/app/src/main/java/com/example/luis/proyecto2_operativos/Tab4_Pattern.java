package com.example.luis.proyecto2_operativos;

import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.Toast;

import com.andrognito.patternlockview.PatternLockView;
import com.andrognito.patternlockview.listener.PatternLockViewListener;
import com.andrognito.patternlockview.utils.PatternLockUtils;

import java.util.List;

/**
 * Created by luis on 13/11/2017.
 */

public class Tab4_Pattern extends Fragment {

    String final_pattern = "";
    boolean flagNew = false;
    PatternLockView mPatternLockView;
    Button button;
    String save_pattern = "";

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        final View rootView = inflater.inflate(R.layout.tab4_pattern, container, false);

        button = rootView.findViewById(R.id.btnSetPattern);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                flagNew = true;
            }
        });


        mPatternLockView = rootView.findViewById(R.id.pattern_lock_view);
        mPatternLockView.addPatternLockListener(new PatternLockViewListener() {
            @Override
            public void onStarted() {

            }

            @Override
            public void onProgress(List<PatternLockView.Dot> progressPattern) {

            }

            @Override
            public void onComplete(List<PatternLockView.Dot> pattern) {
                String mensaje = "";
                if(flagNew){
                    save_pattern = PatternLockUtils.patternToString(mPatternLockView, pattern);
                    mensaje = "Patron Creado";
                }else{
                    final_pattern = PatternLockUtils.patternToString(mPatternLockView, pattern);
                    mensaje = "PIN Incorrecto";
                    if(final_pattern.equals(save_pattern)){
                        mensaje = "PIN Correcto";
                    }
                }
                flagNew = false;
                Toast.makeText(getContext(), mensaje, Toast.LENGTH_SHORT).show();
            }

            @Override
            public void onCleared() {

            }
        });




        return rootView;
    }
}
