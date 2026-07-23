<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <xsl:template match="/">
        <html>
            <head>
                <title>Student Catalog</title>
                <style>
                    body {
                        font-family: Arial, sans-serif;
                        background-color: #f4f4f9;
                        padding: 20px;
                    }
                    h2 {
                        text-align: center;
                        color: #333;
                    }
                    table {
                        width: 80%;
                        margin: 0 auto;
                        border-collapse: collapse;
                        box-shadow: 0 4px 8px rgba(0,0,0,0.1);
                        background-color: white;
                    }
                    th, td {
                        padding: 12px 15px;
                        border: 1px solid #ddd;
                        text-align: left;
                    }
                    th {
                        background-color: #007bff;
                        color: white;
                        text-transform: uppercase;
                        letter-spacing: 0.05em;
                    }
                    tr:nth-child(even) {
                        background-color: #f9f9f9;
                    }
                    tr:hover {
                        background-color: #f1f1f1;
                    }
                </style>
            </head>
            <body>
                <h2>Student Information Catalog</h2>
                <table>
                    <tr>
                        <th>Enrollment No</th>
                        <th>Name</th>
                        <th>Contact No</th>
                        <th>Email ID</th>
                    </tr>
                    <xsl:for-each select="Students/Student">
                        <tr>
                            <td><xsl:value-of select="EnrolNo"/></td>
                            <td><xsl:value-of select="Name"/></td>
                            <td><xsl:value-of select="ContactNo"/></td>
                            <td><xsl:value-of select="EmailID"/></td>
                        </tr>
                    </xsl:for-each>
                </table>
            </body>
        </html>
    </xsl:template>
</xsl:stylesheet>
