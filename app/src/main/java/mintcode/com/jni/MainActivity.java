package mintcode.com.jni;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.EdgeEffect;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import butterknife.Bind;
import butterknife.ButterKnife;
import butterknife.OnClick;

public class MainActivity extends AppCompatActivity {

    private TextView textView;
    private TextView swapTV;
    @Bind(R.id.first)
    EditText firstET;
    @Bind(R.id.second)
    EditText secondET;
    private Ndk ndk;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        ButterKnife.bind(this);
        swapTV = (TextView) findViewById(R.id.swap_value);
        textView = (TextView) findViewById(R.id.text_view);
        ndk = new Ndk("mintcode");
        textView.setText(ndk.convert("abc"));

    }

    @OnClick(R.id.swap_value)
    public void swap() {
        String first = "a";
        String second = "b";
        ndk.swapValue(first, second);
        Toast.makeText(MainActivity.this, first + " " + second, Toast.LENGTH_SHORT).show();
    }

}
