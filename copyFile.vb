Sub Vordienstzeit()
    Dim SourceFile, DestinationFile
    Dim dest_wb As Workbook
    Dim dest_ws As Worksheet
    Dim curr_ws As Worksheet
    
    SourceFile = ".\Vordienstzeiten_Gastronomie KV_final_Formel_Vorlage Anrechnung.xltx"
    DestinationFile = ".\Vordienstzeiten\Vordienstzeit_Siebenförcher_Florian.xltx"
    FileCopy SourceFile, DestinationFile
    
    Application.ScreenUpdating = False
    
    Set dest_wb = Workbooks.Open(DestinationFile)
    Set dest_ws = dest_wb.Sheets("Tabelle1")
    dest_ws.Cells(3, 2).Value = "Siebenförcher Florian"
    
    dest_wb.Close True, DestinationFile
    Application.ScreenUpdating = True
End Sub
