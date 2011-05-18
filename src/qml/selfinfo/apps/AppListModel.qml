import Qt 4.7

ListModel {
        id: mymodel
        Component.onCompleted: loadPlugin()
        function loadPlugin() {
            var db = openDatabaseSync("plugin.dat", "1.0", "My model SQL", 50000);
            db.transaction(
                function(tx) {
                    var rs = tx.executeSql('SELECT * FROM PLUGINTABLE');
                    var index = 0;
                    if (rs.rows.length > 0) {
                        var index = 0;
                        while (index < rs.rows.length) {
                            var myItem = rs.rows.item(index);
                            mymodel.append( {
                                "name": myItem.name,
                                "title": myItem.title ,
                                 "icon":myItem.icon });
                            index++;
                        }
                    } else {
                        mymodel.append( {
                            "name": 1,
                            "title": 'apple' ,
                            "icon": 'content/pics/apple.png'  });
                        mymodel.append( {
                            "name": 2,
                            "title": 'Qt Quick!' ,
                            "icon": 'content/pics/Qt.png'  });
                        }
                }
            )
        }
    }
