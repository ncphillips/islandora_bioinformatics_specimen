<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
    xmlns:xs="http://www.w3.org/2001/XMLSchema"
    xmlns:specimen="http://107.170.42.52/"
    exclude-result-prefixes="xs"
    version="1.0">
    <xsl:template match="/">
        <eml:eml xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
            xsi:schemaLocation="http://nis.lternet.edu/schemas/EML/eml-2.1.0/eml.xsd"
            xmlns:eml="eml://ecoinformatics.org/eml-2.1.0" packageId="ppound.3.1" system="knb">
            <dataset>
                <shortName><xsl:value-of select="/specimen:specimen/specimen:taxonomy/specimen:species"/></shortName>
                <coverage>
                    <!-- see http://knb.ecoinformatics.org/software/eml/eml-2.1.1/eml-coverage.html-->
                    <taxonomicCoverage>
                        <taxonomicClassification>
                            <taxonRankName>phylum</taxonRankName>
                            <taxonRankValue><xsl:value-of select="/specimen:specimen/specimen:taxonomy/specimen:phylum"/></taxonRankValue>
                        </taxonomicClassification>
                        <taxonomicClassification>
                            <taxonRankName>subPhylum</taxonRankName>
                            <taxonRankValue><xsl:value-of select="/specimen:specimen/specimen:taxonomy/specimen:subphylum"/></taxonRankValue>
                        </taxonomicClassification>
                        <taxonomicClassification>
                            <taxonRankName>class</taxonRankName>
                            <taxonRankValue><xsl:value-of select="/specimen:specimen/specimen:taxonomy/specimen:class"/></taxonRankValue>
                        </taxonomicClassification>
                        <taxonomicClassification>
                            <taxonRankName>order</taxonRankName>
                            <taxonRankValue><xsl:value-of select="/specimen:specimen/specimen:taxonomy/specimen:order"/></taxonRankValue>
                        </taxonomicClassification>
                        <taxonomicClassification>
                            <taxonRankName>Family</taxonRankName>
                            <taxonRankValue><xsl:value-of select="/specimen:specimen/specimen:taxonomy/specimen:family"/></taxonRankValue>
                        </taxonomicClassification>
                        <taxonomicClassification>
                            <taxonRankName>Genus</taxonRankName>
                            <taxonRankValue><xsl:value-of select="/specimen:specimen/specimen:taxonomy/specimen:genus"/></taxonRankValue>
                        </taxonomicClassification>
                        <taxonomicClassification>
                            <taxonRankName>species</taxonRankName>
                            <taxonRankValue><xsl:value-of select="/specimen:specimen/specimen:taxonomy/specimen:species"/></taxonRankValue>
                        </taxonomicClassification>
                    </taxonomicCoverage>
                </coverage>
            </dataset>
        </eml:eml>
    </xsl:template>
</xsl:stylesheet>