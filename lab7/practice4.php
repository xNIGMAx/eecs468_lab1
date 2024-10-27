<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Practice 4 - Multiplication Table</title>
    <style>
        table {
            border-collapse: collapse;
            margin-top: 20px;
        }
        td {
            border: 1px solid #000;
            padding: 10px;
            text-align: center;
        }
    </style>
</head>
<body>
    <form method="POST">
        <label>Enter a Number:</label>
        <input type="number" name="number" required>

        <button type="submit">Multiply</button>
    </form>
    <div>
        <?php
            if ($_POST){
                $num = $_POST["number"];
                
                echo "<table>";
                for ($i = 1; $i <= $num; $i++){
                    echo "<tr>";
                    for ($j = 1; $j <= $num; $j++){
                        echo "<td>" . ($i * $j) . "</td>"; // Each number in a table cell
                    }
                    echo "</tr>"; // End the table row
                }
                echo "</table>"; // End the table
            }
        
        
        ?>
    </div>
</body>
</html>


