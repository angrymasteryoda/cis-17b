<style>
body > div {
    color: cyan;
    height: 150px;
    overflow: scroll;
}
body {
    color: #666;
}
</style>
<body>header
    <div id="header"></div>slots
    <div id="slot"></div>functions
    <div id="body"></div>set cell
    <div id="set"><pre></pre></div>get cell
    <div id="get"><pre></pre></div>
</body>
<script>
$(document).ready(function () {
    for (var i = 0; i < 9; i++) {
        for (var j = 0; j < 9; j++) {
            $('#header').append('<div>void on_cell_' + i + '_' + j + '_blur();</div>');
        }
    }

    for (var i = 0; i < 9; i++) {
        for (var j = 0; j < 9; j++) {
            $('#slot').append('<div>ui->cell_' + i + '_' + j + '->setInputMask( "D" );</div>');
            $('#slot').append('<div>connect( ui->cell_' + i + '_' + j + ', ' +
                'SIGNAL( editingFinished() ), ' +
                'this, ' +
                'SLOT( on_cell_' + i + '_' + j + '_blur() ) );</div>');
        }
    }
    

    for (var i = 0; i < 9; i++) {
        for (var j = 0; j < 9; j++) {
            $('#body').append('<div>void GameWindow::on_cell_' + i + '_' + j + '_blur(){qDebug()<< "cell_' + i + '_' + j + ' slot";}</div>');
        }
    }

    //set cell
    for (var i = 0; i < 9; i++) {
        s('if( row == ' + i + ' ){\n' );
        for (var j = 0; j < 9; j++) {
            s('\tif( col == ' + j + ' ) { ui->cell_' + i + '_' + j + '->setText( QString::number( set ) ) ; return;}\n');
        }
        s('}\n' );
    }
    
    for (var i = 0; i < 9; i++) {
        g('if( row == ' + i + ' ){\n' );
        for (var j = 0; j < 9; j++) {
            g('\tif( col == ' + j + ' ) { return ui->cell_' + i + '_' + j + '->text() ; }\n');
        }
        g('}\n' );
    }

    function s(s){$('#set pre').append(s);}
    function g(s){$('#get pre').append(s);}
        
});
</script>