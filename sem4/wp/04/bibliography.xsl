<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  <xsl:template match="/">
    <html>
      <head>
        <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css" integrity="sha384-BVYiiSIFeK1dGmJRAkycuHAHRg32OmUcww7on3RYdg4Va+PmSTsz/K68vbdEjh4u" crossorigin="anonymous"/>
      </head>
      <body>
        <div class="col-md-8 col-md-offset-2">
          <h2>Bibliography</h2>
          <table class="table table-bordered table-condensed">
            <tr class="bg-primary text-uppercase">
              <th class="col-md-7">Title</th>
              <th class="col-md-2">Author</th>
              <th class="col-md-3">Details</th>
            </tr>
            <xsl:for-each select="bibliography/entry">
              <xsl:sort select="author"/>
              <xsl:sort select="title"/>
              <xsl:variable name="row_type">
                <xsl:choose>
                  <xsl:when test="@category='web_link'">
                    <xsl:text>active</xsl:text>
                  </xsl:when>
                  <xsl:when test="@category='book'">
                    <xsl:text>success</xsl:text>
                  </xsl:when>
                  <xsl:when test="@category='report'">
                    <xsl:text>info</xsl:text>
                  </xsl:when>
                  <xsl:when test="@category='article'">
                    <xsl:text>warning</xsl:text>
                  </xsl:when>
                  <xsl:when test="@category='presentation'">
                    <xsl:text>danger</xsl:text>
                  </xsl:when>
                </xsl:choose>
              </xsl:variable>
              <xsl:element name="tr">
                <xsl:attribute name="class">
                  <xsl:value-of select="$row_type"/>
                </xsl:attribute>
                <td class="h5"><xsl:value-of select="title"/></td>
                <td><xsl:value-of select="author"/></td>
                <td>
                  <xsl:value-of select="editor"/>,
                  P <xsl:value-of select="num_pages"/>,
                  <xsl:value-of select="publication_year"/>
                </td>
              </xsl:element>
            </xsl:for-each>
          </table>
          <i>Disclaimer: Information about entries are random.</i>
        </div>
      </body>
    </html>
  </xsl:template>
</xsl:stylesheet>
