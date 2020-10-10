#We will be using PyPDF2 lib
import PyPDF2

import sys #used to take input from system

inputs = sys.argv[1:]

def pdf_merging(pdfs):
	merger = PyPDF2.PdfFileMerger()
	for pdf in pdfs:
		# print(pdf)
		merger.append(pdf)
	merger.write('merged.pdf') #output file name

pdf_merging(inputs)
