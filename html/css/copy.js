// copy.js
function copyCode(codeId) {
    // Megkeressük a code elemet
    let code = document.getElementById(codeId).innerText;
    // Átalakítjuk az entitásokat <>-re
    code = code.replace(/&lt;/g, "<").replace(/&gt;/g, ">");
    // Clipboard API-val másoljuk
    navigator.clipboard.writeText(code)
        .then(() => {
            alert("Kód kimásolva a vágólapra!");
        })
        .catch(err => {
            console.error("Hiba a másolásnál:", err);
        });
}
