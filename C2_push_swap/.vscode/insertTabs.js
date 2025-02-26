const vscode = require('vscode');

function calculateAndInsertTabs() {
    const editor = vscode.window.activeTextEditor;
    if (!editor) {
        return; // No active editor
    }

    const document = editor.document;
    const selection = editor.selection;
    const currentLine = document.lineAt(selection.active.line);
    const lineLength = currentLine.text.length;

    const targetSpaces = 19 * 4; // 76 spaces
    const spacesNeeded = targetSpaces - lineLength;
    const tabsNeeded = Math.ceil(spacesNeeded / 4); // Assuming 4 spaces per tab

    if (tabsNeeded <= 0) {
        return; // No tabs needed
    }

    const tabsToInsert = "\t".repeat(tabsNeeded);

    editor.edit(editBuilder => {
        editBuilder.insert(selection.active, tabsToInsert);
    });
}

module.exports = {
    calculateAndInsertTabs
};