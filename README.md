# CPDF

CPDF (for _Compress PDF_) is a small wrapper around ghostscript to ease the compression of pdf files. This is useful because my scanner produces very large files for simple documents I then need to send by mail :slightly_smiling_face:

CPDF requires [ghostscript](https://www.ghostscript.com/) and won't work without it. This code was inspired by [an article from itsfoss.com](https://itsfoss.com/compress-pdf-linux/).

## Usage

```
cpdf [quality] input_pdf_file output_pdf_file

Where:
 - quality is one of "--low", "--medium", "--high". Default is "--medium".
 - input_pdf_file is the pdf file that we want to compress.
 - output_pdf_file is the path where we want the created pdf file to go.
```

## Installing

CPDF uses a simple Makefile and can be installed using `make install`, provided a suitable C compiler is available.

### METADATA

Field | Value
--- | ---
:pencil: Contributors | roadelou
:email: Contacts | 
:date: Creation Date | 2021-01-28
:bulb: Language | Markdown Document

### EOF
